#pragma once


#include "CollisionShape.h"

namespace Lumos
{

	class LUMOS_EXPORT CapsuleCollisionShape : public CollisionShape
	{
	public:
		CapsuleCollisionShape(float radius = 1.0f, float height = 1.0f);
		~CapsuleCollisionShape();

		//Collision Shape Functionality
		virtual Maths::Matrix3 BuildInverseInertia(float invMass) const override;

		virtual void GetCollisionAxes(const RigidBody3D* currentObject, std::vector<Maths::Vector3>* out_axes) const override;
		virtual void GetEdges(const RigidBody3D* currentObject, std::vector<CollisionEdge>* out_edges) const override;

		virtual void GetMinMaxVertexOnAxis(const RigidBody3D* currentObject, const Maths::Vector3& axis, Maths::Vector3* out_min, Maths::Vector3* out_max) const override;
		virtual void GetIncidentReferencePolygon(const RigidBody3D* currentObject, const Maths::Vector3& axis, std::list<Maths::Vector3>* out_face, Maths::Vector3* out_normal, std::vector<Maths::Plane>* out_adjacent_planes) const override;

		virtual void DebugDraw(const RigidBody3D* currentObject) const override;

		//Get/Set Sphere Radius
		void SetRadius(float radius)
		{
			m_Radius = radius;
			m_LocalTransform = Maths::Matrix4::Scale(Maths::Vector3(m_Radius));
		}

		float GetRadius() const
		{
			return m_Radius;
		}

		float GetSize() const override
		{
			return m_Radius;
		}

	protected:
		float m_Radius;
		float m_Height;
	};
}
